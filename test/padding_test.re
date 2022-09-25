open Framework;

describe("box.render(~padding)", ({test, _}) => {
  test("renders a box with padding", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Box.Padding.all(2), "foo"),
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
      Box.render(~padding=Box.Padding.bottom(2), "foo"),
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
      Box.render(~padding=Box.Padding.top(2), "foo"),
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
      Box.render(~padding=Box.Padding.left(2), "foo"),
      {|
╭─────╮
│  foo│
╰─────╯
|},
    )
  );

  test("renders a box with padding right", ({expect, _}) =>
    expect |> equal(
      Box.render(~padding=Box.Padding.right(2), "foo"),
      {|
╭─────╮
│foo  │
╰─────╯
|},
    )
  );

});
