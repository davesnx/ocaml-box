open Framework;

describe("box.render(~border)", ({test, _}) => {
  test("Border.Classic should render a box with classic's border", ({expect, _}) =>
    expect |> equal(
      Box.render(~border=Border.Classic, "foo"),
      {|
+---+
|foo|
+---+
|},
    )
  );

  test("Border.Custom should renders a box with custom border", ({expect, _}) =>
    expect |> equal(
      Box.render(
        ~border=
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
1...2
.foo.
4...3
|},
    )
  );
});
