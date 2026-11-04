FROM ubuntu:24.04 AS build

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        autoconf \
        automake \
        build-essential \
        libluajit-5.1-dev \
        libpng-dev \
        libtool \
        pkg-config \
        zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src/libtexpdf
COPY *.c *.h Makefile.am configure.ac LICENSE ./
COPY dvipdfm-x/ dvipdfm-x/
COPY build-aux/ build-aux/
COPY lua/ lua/

RUN autoreconf -fi \
    && ./configure --prefix=/usr/local --enable-shared --disable-static \
    && make -j"$(nproc)" \
    && make check \
    && make install \
    && test -s /usr/local/lib/libtexpdf.so

RUN mkdir -p /usr/local/lib/lua/5.1 \
    && cc -std=gnu11 -fPIC -shared $(pkg-config --cflags luajit) \
        -I/usr/local/include/libtexpdf \
        lua/justenoughlibtexpdf.c \
        -L/usr/local/lib -Wl,-rpath,/usr/local/lib -ltexpdf $(pkg-config --libs luajit) \
        -o /usr/local/lib/lua/5.1/justenoughlibtexpdf.so

FROM ubuntu:24.04

RUN apt-get update \
    && apt-get install -y --no-install-recommends libluajit-5.1-2 libpng16-16t64 zlib1g \
    && rm -rf /var/lib/apt/lists/*

COPY --from=build /usr/local/ /usr/local/
RUN ldconfig

CMD ["/bin/bash"]