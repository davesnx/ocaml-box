(lang dune 2.7)
(name box)
(version 1.2.0)
(source (github davesnx/ocaml-box))
(license MIT)
(authors "davesnx <dsnxmoreno@gmail.com>")
(documentation "https://davesnx.github.io/ocaml-box/box/index.html")
(maintainers "davesnx <dsnxmoreno@gmail.com>")

(generate_opam_files false)

(package
 (name box)
 (synopsis "Render boxes in the terminal")
 (description "\
Render boxes in the terminal, can configure the padding, margin and the border of the box.
")
 (depends
  (ocaml (>= 4.08.0))
  (dune (>= 2.7))
  ; Add Rely when released on Opam
  ; (rely :with-test)
  (odoc :with-doc)
  (reason :build)
 )
)
