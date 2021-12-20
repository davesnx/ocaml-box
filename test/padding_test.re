open Framework;

describe("box.render(~padding)", ({test, _}) => {
  test("renders a box with padding", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Padding.all(2), "foo"),
      {|
╭───────╮
│       │
│       │
│  foo  │
│       │
│       │
╰───────╯
|},
    )
  );

  test("renders a box with padding bottom", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Padding.bottom(2), "foo"),
      {|
╭───╮
│foo│
│   │
│   │
╰───╯
|},
    )
  );

  test("renders a box with padding top", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Padding.top(2), "foo"),
      {|
╭───╮
│   │
│   │
│foo│
╰───╯
|},
    )
  );

  test("renders a box with padding left", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Padding.left(2), "foo"),
      {|
╭─────╮
│  foo│
╰─────╯
|},
    )
  );

  test("renders a box with padding right", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Padding.right(2), "foo"),
      {|
╭─────╮
│foo  │
╰─────╯
|},
    )
  );

});
