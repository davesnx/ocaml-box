/* It can be used in either OCaml, either Reason, showing the usage in Reason:

```reason
print_endline(
  Box.render(~padding=Padding.all(2), "I love unicorns")
);
/*
┌─────────────────────┐
│                     │
│   I love unicorns   │
│                     │
└─────────────────────┘
*/

print_endline(
  Box.render(~margin=Margin.all(2), ~padding=Padding.all(2), "I love unicorns")
);
/*


    ┌─────────────────────┐
    │                     │
    │   I love unicorns   │
    │                     │
    └─────────────────────┘


*/

print_endline(
  Box.render(~kind=Border.Classic, ~margin=Margin.all(2), "I love unicorns")
);
/*


    +-------------------+
    |  I love unicorns  |
    +-------------------+


*/
```

### Interface

```reason
let render: (
  ~padding: int=?,
  ~margin: int=?,
  ~kind: Border.t=?,
  string
) => string;
```

While the documentation isn't published. Check `lib/box.rei` and `lib/border.rei`.
 */

module Border = Border;
module Padding = Padding;
module Margin = Margin;

type position = [ | `Left | `Center | `Right];

let render: (~align: position=?, ~float: position=?, ~padding: Padding.t=?, ~margin: Margin.t=?, ~border: Border.t=?, string) => string;
