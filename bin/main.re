/* This file's purpose is to test manually and isn't public, it might serve as examples! */

print_endline(
  Box.render(
    ~margin=2,
    ~padding=0,
    ~align=`Left,
    "box",
  )
);

print_endline("     xxxxxxxxxxxxxxxxxx");

print_endline(
  Box.render(
    ~margin=2,
    ~padding=2,
    ~align=`Center,
    "This \nis \na sentence",
  )
);

print_endline("     xxxxxxxxxxxxxxxxxx");

print_endline(
  Box.render(
    ~margin=2,
    ~padding=2,
    ~align=`Right,
    "OMG\nTHAT'S PROPER BOX",
  )
);
