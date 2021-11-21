/* This file's purpose is to test manually and isn't public, it might serve as examples! */

/* let separator = Box.render(
  ~float=`Left,
  ~align=`Center,
  ~border=Custom({
    topLeft: "",
    top: "",
    topRight: "",
    right: "",
    bottomRight: "",
    bottom: "",
    bottomLeft: "",
    left: "",
  }),
  "xxxxxxxxxxxxxxxxxx",
);

print_endline(
  Box.render(
    ~margin=Margin.all(2),
    ~align=`Left,
    "box",
  )
);

print_endline(separator);
 */
print_endline(
  Box.render(~margin=Margin.all(2), "foo")
);
