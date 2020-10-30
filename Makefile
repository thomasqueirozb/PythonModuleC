NAME=testc



.PHONY: test install uninstall clean
test: install
	pytest

install:
	python setup.py build
	python setup.py install --user


PYTHON_VERSION=$(shell python --version | awk '{print $$2}' | awk -F'.' '{printf "%s.%s\n", $$1, $$2}')
uninstall:
	rm ~/.local/lib/python$(PYTHON_VERSION)/site-packages/$(NAME).cpython-38-x86_64-linux-gnu.so
	rm ~/.local/lib/python$(PYTHON_VERSION)/site-packages/$(NAME)-1.0-py3.8.egg-info

clean:
	rm -rf build/
