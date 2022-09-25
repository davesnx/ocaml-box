open Framework;

describe("box.render(~margin)", ({test, _}) => {
  test("should render a box with space arround", ({expect, _}) =>
    expect |> equal(
      Box.render(~margin=Box.Margin.all(2), "foo"),
      {|


    ╭───╮
    │foo│
    ╰───╯

|},
    )
  );
});
