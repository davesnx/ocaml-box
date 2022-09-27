.DEFAULT_GOAL := all

BROWSER := python -c "$$BROWSER_PYSCRIPT"
DUNE = opam exec -- dune

ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(ARGS):;@:)

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";


.PHONY: all
all:
	$(DUNE) build --root . @install

.PHONY: create-switch
create-switch:
	opam switch create . 4.12.0 --deps-only --locked

.PHONY: pin-reason-native
pin-reason-native:
	git submodule update --init

.PHONY: dev
init: pin-reason-native ## Install development dependencies
	git config core.hooksPath .githooks
	opam pin add -y ocaml-lsp-server https://github.com/ocaml/ocaml-lsp.git
	opam install -y dune-release merlin ocaml-lsp-server
	opam install --deps-only --with-test --with-doc -y .

.PHONY: install
install: all ## Install the packages on the system
	$(DUNE) install --root .

.PHONY: start
start: all ## Run the produced executable
	$(DUNE) exec --root . bin/main.exe $(ARGS)

.PHONY: watch
dev: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --root . --watch

.PHONY: test
test: ## Run the unit tests
	$(DUNE) exec --root . test/runner.exe

.PHONY: build
build: ## Build the project, including non installable libraries and executables
	$(DUNE) build --root .

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	$(DUNE) clean --root .

.PHONY: doc
doc: ## Generate odoc documentation
	$(DUNE) build --root . @doc

.PHONY: servedoc
servedoc: doc ## Open odoc documentation with default web browser
	open _build/default/_doc/_html/index.html

.PHONY: format
format: ## Format the codebase with ocamlformat
	$(DUNE) build --root . --auto-promote @fmt

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --root . --watch

.PHONY: utop
utop: ## Run a REPL and link with the project's libraries
	$(DUNE) utop --root . lib -- -implicit-bindings

.PHONY: release
release: all ## Run the release script
	opam exec -- sh script/release.sh
