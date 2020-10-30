#!/usr/bin/env python3
from distutils.core import setup, Extension

module1 = Extension("testc", sources=["testc.c"])

setup(name="testc", version="1.0", description="This is a demo package", ext_modules=[module1])
