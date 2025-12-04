open Alcotest

let test_render_box_with_margin_and_padding () =
  let expected =
    String.trim
      {|
    ╭───────╮
    │       │
    │       │
    │  foo  │
    │       │
    │       │
    ╰───────╯

|}
  in
  let actual =
    String.trim
      (Box.render ~margin:(Box.Margin.all 2) ~padding:(Box.Padding.all 2) "foo")
  in
  check string "should render a box with both combined" expected actual

let tests =
  [
    ( "box.render(~margin, ~padding)",
      `Quick,
      test_render_box_with_margin_and_padding );
  ]
