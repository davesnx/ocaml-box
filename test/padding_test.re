open Test_framework;

let equal = (s1, s2, expect) => {
  expect.string(String.trim(s1)).toEqual(String.trim(s2));
};

describe("box.render(~padding)", ({test, _}) => {
  test("renders a box with padding", ({expect, _}) =>
    expect |>equal(
      Box.render(~padding=Padding.all(2), "foo"),
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
