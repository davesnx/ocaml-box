/* This file's purpose is to test manually and isn't public, it might serve as examples! */

let separator = Box.render(
  ~margin=0,
  ~padding=0,
  ~float=`Left,
  ~align=`Center,
  ~kind=Custom({
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
    ~margin=2,
    ~padding=0,
    ~align=`Left,
    "box",
  )
);

print_endline(separator);

print_endline(
  Box.render(
    ~margin=2,
    ~padding=2,
    ~align=`Center,
    ~float=`Center,
    "This \nis \na sentence",
  )
);
