.DEFAULT_GOAL := all

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";


.PHONY: all
all:
	dune build --root . @install

.PHONY: init
init: ## Install development dependencies
	dune pkg lock
	dune build @install

.PHONY: start
start: all ## Run the produced executable
	dune exec --root . bin/main.exe $(ARGS)

.PHONY: watch
dev: ## Watch for the filesystem and rebuild on every change
	dune build --root . --watch

.PHONY: test
test: ## Run the unit tests
	dune runtest --root .

.PHONY: build
build: ## Build the project, including non installable libraries and executables
	dune build --root .

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	dune clean --root .

.PHONY: doc
doc: ## Generate odoc documentation
	dune build --root . @doc

.PHONY: servedoc
servedoc: doc ## Open odoc documentation with default web browser
	open _build/default/_doc/_html/index.html

.PHONY: format
format: ## Format the codebase with ocamlformat
	dune build --root . --auto-promote @fmt

.PHONY: format-check
format-check: ## Checks if format is correct
	dune build @fmt

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	dune build --root . --watch

.PHONY: utop
utop: ## Run a REPL and link with the project's libraries
	dune utop --root . lib -- -implicit-bindings

.PHONY: release
release: all ## Run the release script
	./script/release.sh
