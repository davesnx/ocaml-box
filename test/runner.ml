open Alcotest

let () =
  run "ocaml-box"
    [
      ("box.render()", Box_test.tests);
      ("box.render(~margin)", Margin_test.tests);
      ("box.render(~margin, ~padding)", Margin_padding_test.tests);
      ("box.render(~padding)", Padding_test.tests);
      ("box.render(~border)", Border_test.tests);
    ]
