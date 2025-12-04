open Alcotest

let test_render_box_with_margin () =
  let expected = String.trim {|
    ╭───╮
    │foo│
    ╰───╯

|} in
  let actual = String.trim (Box.render ~margin:(Box.Margin.all 2) "foo") in
  check string "should render a box with space around" expected actual

let tests = [ ("box.render(~margin)", `Quick, test_render_box_with_margin) ]
