open Alcotest

let test_render_box_with_classic_border () =
  let expected = String.trim {|
+---+
|foo|
+---+
|} in
  let actual = String.trim (Box.render ~border:Box.Border.Classic "foo") in
  check string "Border.Classic should render a box with classic's border"
    expected actual

let test_render_box_with_custom_border () =
  let expected = String.trim {|
1...2
.foo.
4...3
|} in
  let actual =
    String.trim
      (Box.render
         ~border:
           (Box.Border.Custom
              {
                topLeft = {|1|};
                top = {|.|};
                topRight = {|2|};
                right = {|.|};
                bottomRight = {|3|};
                bottom = {|.|};
                bottomLeft = {|4|};
                left = {|.|};
              })
         "foo")
  in
  check string "Border.Custom should renders a box with custom border" expected
    actual

let tests =
  [
    ( "Border.Classic should render a box with classic's border",
      `Quick,
      test_render_box_with_classic_border );
    ( "Border.Custom should renders a box with custom border",
      `Quick,
      test_render_box_with_custom_border );
  ]
