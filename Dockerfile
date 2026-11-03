FROM ubuntu:24.04 AS build

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        autoconf \
        automake \
        build-essential \
        libkpathsea-dev \
        libpng-dev \
        libtool \
        pkg-config \
        zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src/libtexpdf
COPY *.c *.h Makefile.am configure.ac LICENSE ./
COPY dvipdfm-x/ dvipdfm-x/
COPY build-aux/ build-aux/

RUN autoreconf -fi \
    && ./configure --prefix=/usr/local --enable-shared --disable-static LIBS=-lkpathsea \
    && make -j"$(nproc)" \
    && make check \
    && make install \
    && test -s /usr/local/lib/libtexpdf.so

FROM ubuntu:24.04

RUN apt-get update \
    && apt-get install -y --no-install-recommends libkpathsea6 libpng16-16t64 zlib1g \
    && rm -rf /var/lib/apt/lists/*

COPY --from=build /usr/local/ /usr/local/
RUN ldconfig

CMD ["/bin/bash"]