open Framework;

describe("box.render()", ({test, _}) => {
  test("should render a box", ({expect, _}) =>
    expect |> equal(
      Box.render("foo"),
      {|
╭───╮
│foo│
╰───╯
|},
    )
  );
});
