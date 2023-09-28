%global commit0 f648516e76ac1514bbb8585585d814b0446a3399
%global shortcommit0 %(c=%{commit0}; echo ${c:0:7})
%global date0 20230923
%global upstream_name XNNPACK
# This project is not well behaved so build in source
%define __cmake_in_source_build 1
# No debug info
%global debug_package %{nil}

Summary:        High-efficiency floating-point neural network inference operators
Name:           xnnpack
License:        BSD-3-Clause
Version:        1.0^git%{date0}.%{shortcommit0}
Release:        1%{?dist}

URL:            https://github.com/google/%{upstream_name}
Source0:        %{url}/archive/%{commit0}/%{name}-%{shortcommit0}.tar.gz
Patch0:         0001-Prepare-xnnpack-cmake-for-fedora.patch

ExclusiveArch:  x86_64 aarch64

BuildRequires:  cmake
BuildRequires:  cpuinfo-devel
BuildRequires:  FP16-devel
BuildRequires:  fxdiv-devel
BuildRequires:  gcc-c++
BuildRequires:  make
BuildRequires:  pthreadpool-devel

%description
XNNPACK is a highly optimized solution for neural network inference on ARM,
x86, WebAssembly, and RISC-V platforms. XNNPACK is not intended for direct
use by deep learning practitioners and researchers; instead it provides
low-level performance primitives for accelerating high-level machine learning
frameworks, such as TensorFlow Lite, TensorFlow.js, PyTorch, ONNX Runtime,
and MediaPipe.

%package devel
Summary:        Headers and libraries for %{name}
Requires:       %{name}%{?_isa} = %{version}-%{release}

%description devel
%{summary}

%prep
%autosetup -p1 -n %{upstream_name}-%{commit0}

%build
%cmake \
      -G Ninja \
      -DBUILD_SHARED_LIBS=ON \
      -DCMAKE_C_FLAGS=-fPIC \
      -DCMAKE_CXX_FLAGS=-fPIC \
      -DXNNPACK_BUILD_BENCHMARKS=OFF \
      -DXNNPACK_BUILD_LIBRARY=ON \
      -DXNNPACK_BUILD_TESTS=OFF \
      -DXNNPACK_USE_SYSTEM_LIBS=ON \
      -DXNNPACK_LIBRARY_TYPE=shared

%cmake_build

%install
mkdir -p %{buildroot}%{_includedir}
install -p -m 644 include/xnnpack.h %{buildroot}%{_includedir}
mkdir -p %{buildroot}%{_libdir}
install -p -m 755 libXNNPACK.so* %{buildroot}%{_libdir}

# building tests or benchmarks is broken
# %check
# ctest

%files
%license LICENSE
%{_libdir}/libXNNPACK.so.*

%files devel
%doc README.md
%{_includedir}/xnnpack.h
%{_libdir}/libXNNPACK.so

%changelog
* Sat Sep 23 2023 Tom Rix <trix@redhat.com> - 23.2.14-1.giteb4a667
- Initial package
