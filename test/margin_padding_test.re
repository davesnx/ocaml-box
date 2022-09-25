open Framework;

describe("box.render(~margin, ~padding)", ({test, _}) => {
  test("should render a box with both combined", ({expect, _}) =>
    expect |> equal(
      Box.render(~margin=Box.Margin.all(2), ~padding=Box.Padding.all(2), "foo"),
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
});
