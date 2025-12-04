open Alcotest

let test_render_box_with_padding () =
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
  let actual = String.trim (Box.render ~padding:(Box.Padding.all 2) "foo") in
  check string "renders a box with padding" expected actual

let test_render_box_with_padding_bottom () =
  let expected = String.trim {|
╭───╮
│foo│
│   │
│   │
╰───╯
|} in
  let actual = String.trim (Box.render ~padding:(Box.Padding.bottom 2) "foo") in
  check string "renders a box with padding bottom" expected actual

let test_render_box_with_padding_top () =
  let expected = String.trim {|
╭───╮
│   │
│   │
│foo│
╰───╯
|} in
  let actual = String.trim (Box.render ~padding:(Box.Padding.top 2) "foo") in
  check string "renders a box with padding top" expected actual

let test_render_box_with_padding_left () =
  let expected = String.trim {|
╭─────╮
│  foo│
╰─────╯
|} in
  let actual = String.trim (Box.render ~padding:(Box.Padding.left 2) "foo") in
  check string "renders a box with padding left" expected actual

let test_render_box_with_padding_right () =
  let expected = String.trim {|
╭─────╮
│foo  │
╰─────╯
|} in
  let actual = String.trim (Box.render ~padding:(Box.Padding.right 2) "foo") in
  check string "renders a box with padding right" expected actual

let tests =
  [
    ("renders a box with padding", `Quick, test_render_box_with_padding);
    ( "renders a box with padding bottom",
      `Quick,
      test_render_box_with_padding_bottom );
    ("renders a box with padding top", `Quick, test_render_box_with_padding_top);
    ( "renders a box with padding left",
      `Quick,
      test_render_box_with_padding_left );
    ( "renders a box with padding right",
      `Quick,
      test_render_box_with_padding_right );
  ]
