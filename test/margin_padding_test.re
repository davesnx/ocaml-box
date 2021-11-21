open Test_framework;

let equal = (s1, s2, expect) => {
  expect.string(String.trim(s1)).toEqual(String.trim(s2));
};

describe("box.render(~margin, ~padding)", ({test, _}) => {
  test("should render a box with both combined", ({expect, _}) =>
    expect |>equal(
      Box.render(~margin=Margin.all(2), ~padding=Padding.all(2), "foo"),
      {|


    ╭───────────╮
    │           │
    │           │
    │    foo    │
    │           │
    │           │
    ╰───────────╯

|},
    )
  );
});
