/* This isn't publishable */

print_endline(
  Box.render(
        ~kind=
          Border.Custom({
            Border.topLeft: {|1|},
            top: {|.|},
            topRight: {|2|},
            right: {|.|},
            bottomRight: {|3|},
            bottom: {|.|},
            bottomLeft: {|4|},
            left: {|.|},
          }),
        "foo",
      )
);
