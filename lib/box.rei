/** {1 Intro} */

/** Render boxes in the terminal with OCaml or Reason. Port of sindresorhus/boxen.

{[


  ╭─────────────────────────────────────────────────────╮
  │                                                     │
  │   "Render those kinds of boxes in the terminal"     │
  │                                                     │
  ╰─────────────────────────────────────────────────────╯


]}
*/


/** {2 Usage} */

type position = [ | `Left | `Center | `Right];

/** [render text] creates a box around your [text] to print it to the terminal. The text can be aligned to any {!position}, the box can float to any {!position}. Can control the space between the box the the outside with ~padding {!Padding.t} or the space inside with ~margin {!Margin.t}. Lastly, can configure the border to be one of the {!Border.t}
*/
let render: (~align: position=?, ~float: position=?, ~padding: Padding.t=?, ~margin: Margin.t=?, ~border: Border.t=?, string) => string;


/**

  print_endline(
    Box.render(~padding=Padding.all(2), "I love unicorns")
  );

  ┌─────────────────────┐
  │                     │
  │   I love unicorns   │
  │                     │
  └─────────────────────┘

print_endline(
  Box.render(~margin=Margin.all(2), ~padding=Padding.all(2), "I love unicorns")
);

    ┌─────────────────────┐
    │                     │
    │   I love unicorns   │
    │                     │
    └─────────────────────┘


print_endline(
  Box.render(~kind=Border.Classic, ~margin=Margin.all(2), "I love unicorns")
);


    +-------------------+
    |  I love unicorns  |
    +-------------------+
*/

module Border = Border;
module Padding = Padding;
module Margin = Margin;
