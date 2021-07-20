(lang dune 2.0)
(name ocaml-box)
(source (github davesnx/ocaml-box))
(license MIT)
(authors "davesnx")
(maintainers "davesnx")

(generate_opam_files true)

(package
 (name ocaml-box)
 (synopsis "Render boxes in the terminal")
 (description "\
Render boxes in the terminal, can configure the padding, margin and the border of the box.
")
 (depends
  (ocaml (>= 4.08.0))
  (dune (>= 2.0))
  ; Add Rely when released on Opam
  ; (rely :with-test)
  (odoc :with-doc)
  (reason :build)
  cmdliner
  logs
  base
  fmt
 )
)
