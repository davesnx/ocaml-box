(lang dune 2.7)

(name box)

(version 1.2.0)

(generate_opam_files true)

(package
 (name box)
 (synopsis "Render boxes in the terminal")
 (description
  "Render boxes in the terminal, can configure the padding, margin and the border of the box.")
 (authors "davesnx <dsnxmoreno@gmail.com>")
 (maintainers "davesnx <dsnxmoreno@gmail.com>")
 (license "MIT")
 (homepage "https://github.com/davesnx/ocaml-box")
 (bug_reports "https://github.com/davesnx/ocaml-box/issues")
 (depends
  (ocaml
   (>= 4.14.1))
  (odoc
   (and
    (>= 0.20.0)
    :with-doc))
  (alcotest
   (and
    (>= 1.5.0)
    :with-test))))
