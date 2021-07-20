open Test_framework;

let equal = (~expect, s1, s2) => {
  let s1' = String.trim(s1);
  let s2' = String.trim(s2);
  expect.string(s1').toEqual(s2');
};

describe("Box", ({test, _}) => {
  test("renders a box", ({expect, _}) =>
    equal(
      ~expect,
      Box.render("foo"),
      {|
╭───────╮
│  foo  │
╰───────╯
|},
    )
  );

  test("renders a box with round", ({expect, _}) =>
    equal(
      ~expect,
      Box.render(~kind=Border.Classic, "foo"),
      {|
+-------+
|  foo  |
+-------+
|},
    )
  );

  test("renders a box with custom border", ({expect, _}) =>
    equal(
      ~expect,
      Box.render(
        ~kind=
          Border.Custom({
            topLeft: {|1|},
            top: {|.|},
            topRight: {|2|},
            right: {|.|},
            bottomRight: {|3|},
            bottom: {|.|},
            bottomLeft: {|4|},
            left: {|.|},
          }),
        "foo",
      ),
      {|
1.......2
.  foo  .
4.......3
|},
    )
  );

  test("renders a box with padding", ({expect, _}) =>
    equal(
      ~expect,
      Box.render(~padding=2, ~kind=Border.Single, "foo"),
      {|
┌───────────┐
│           │
│           │
│    foo    │
│           │
│           │
└───────────┘
|},
    )
  );

  test("renders a box with margin", ({expect, _}) =>
    equal(
      ~expect,
      Box.render(~margin=2, ~padding=2, ~kind=Border.Single, "foo"),
      {|


    ┌───────────┐
    │           │
    │           │
    │    foo    │
    │           │
    │           │
    └───────────┘

|},
    )
  );
});
