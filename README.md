[![Actions Build Status](https://img.shields.io/github/workflow/status/sile-typesetter/libtexpdf/Build?label=Linux%20Build&logo=Github)](https://github.com/sile-typesetter/libtexpdf/actions?workflow=Build)
[![Build Status](https://simoncozens-github.visualstudio.com/libtexpdf/_apis/build/status/simoncozens.libtexpdf?branchName=master)](https://simoncozens-github.visualstudio.com/libtexpdf/_build/latest?definitionId=1&branchName=master)

## libtexpdf

A PDF authoring library extracted from TeX Live.

## Ubuntu 24.04 Build

```sh
docker build --network=host -t libtexpdf:ubuntu24.04 .
```

The image installs the shared library in `/usr/local/lib` and headers in
`/usr/local/include/libtexpdf`. Runtime dependencies include libpng, zlib, and
Kpathsea (`libkpathsea6` on Ubuntu 24.04).

## Compatibility API

`libtexpdf.c` provides the public `texpdf_*` API, declared in `libtexpdf.h`.
Only `texpdf_*` symbols are exported from the shared library.

The upstream-derived implementation is kept in `dvipdfm-x/`; libtexpdf-specific
API and build files remain at the repository root. See [MIGRATION.md](MIGRATION.md)
for the manual upstream comparison workflow.

