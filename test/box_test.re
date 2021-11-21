open Test_framework;

let equal = (s1, s2, expect) => {
  expect.string(String.trim(s1)).toEqual(String.trim(s2));
};

describe("box.render()", ({test, _}) => {
  test("should render a box", ({expect, _}) =>
    expect |>equal(
      Box.render("foo"),
      {|
╭───────╮
│  foo  │
╰───────╯
|},
    )
  );
});
