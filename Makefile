.DEFAULT_GOAL := all

define BROWSER_PYSCRIPT
import os, webbrowser, sys

from urllib.request import pathname2url

webbrowser.open("file://" + pathname2url(os.path.abspath(sys.argv[1])))
endef
export BROWSER_PYSCRIPT

define PRINT_HELP_PYSCRIPT
import re, sys

for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT

BROWSER := python -c "$$BROWSER_PYSCRIPT"
DUNE = opam exec -- dune

ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(ARGS):;@:)

.PHONY: help
help: ## Print this help message
	@python -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(ARGS):;@:)

.PHONY: all
all:
	$(DUNE) build --root . @install

.PHONY: pin-reason-native
pin-reason-native:
	opam pin add -y pastel https://github.com/facebookexperimental/reason-native.git
	opam pin add -y cli https://github.com/facebookexperimental/reason-native.git
	opam pin add -y file-context-printer https://github.com/facebookexperimental/reason-native.git
	opam pin add -y rely https://github.com/facebookexperimental/reason-native.git

.PHONY: dev
dev: pin-reason-native ## Install development dependencies
	git config core.hooksPath .githooks
	opam pin add -y ocaml-lsp-server https://github.com/ocaml/ocaml-lsp.git
	opam install -y dune-release merlin ocaml-lsp-server
	opam install --deps-only --with-test --with-doc -y .

.PHONY: build
build: ## Build the project, including non installable libraries and executables
	$(DUNE) build --root .

.PHONY: install
install: all ## Install the packages on the system
	$(DUNE) install --root .

.PHONY: start
start: all ## Run the produced executable
	$(DUNE) exec --root . bin/main.exe $(ARGS)

.PHONY: test
test: ## Run the unit tests
	$(DUNE) exec --root . test/test_runner.exe

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	$(DUNE) clean --root .

.PHONY: doc
doc: ## Generate odoc documentation
	$(DUNE) build --root . @doc

.PHONY: servedoc
servedoc: doc ## Open odoc documentation with default web browser
	$(BROWSER) _build/default/_doc/_html/index.html

.PHONY: format
format: ## Format the codebase with ocamlformat
	$(DUNE) build --root . --auto-promote @fmt

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --root . --watch

.PHONY: utop
utop: ## Run a REPL and link with the project's libraries
	$(DUNE) utop --root . lib -- -implicit-bindings

.PHONY: release
release: all ## Run the release script
	opam exec -- sh script/release.sh
