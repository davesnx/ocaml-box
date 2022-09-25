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
