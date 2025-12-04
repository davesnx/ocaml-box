open Alcotest

let test_render_box () =
  let expected = String.trim {|
╭───╮
│foo│
╰───╯
|} in
  let actual = String.trim (Box.render "foo") in
  check string "should render a box" expected actual

let tests = [ ("box.render()", `Quick, test_render_box) ]
