# ocaml-box

```bash

    ╭─────────────────────────────────────────────────╮
    │                                                 │
    │   Render those kinds of boxes in the terminal   │
    │                                                 │
    ╰─────────────────────────────────────────────────╯

```

Render boxes in the terminal with OCaml or Reason.
Port of [sindresorhus/boxen](https://github.com/sindresorhus/boxen).

## Features

- Available on all major platform (Windows, Linux and Windows)
- Render boxes with margin, padding and different borders

### Missing Features

- Alignment
- Floating
- Per direction margin/padding
- Wrap ascii
- Border Color (and dimming)

## Installation

### Using opam

```bash
opam install box
# Since isn't available you can install it with `opam pin https://github.com/davesnx/ocaml-box`
```

### Using esy

```bash
esy add @opam/box
# Since isn't available you can install it with `esy add https://github.com/davesnx/ocaml-box or with a resolution`
```

## Usage

It can be used in either OCaml, either Reason, showing the usage in Reason:

```reason
print_endline(
  Box.render(~padding=2, "I love unicorns")
);
/*
┌─────────────────────┐
│                     │
│   I love unicorns   │
│                     │
└─────────────────────┘
*/

print_endline(
  Box.render(~margin=2, "I love unicorns")
);
/*


    ┌─────────────────────┐
    │                     │
    │   I love unicorns   │
    │                     │
    └─────────────────────┘


*/

print_endline(
  Box.render(~kind=Border.Classic, ~margin=2, "I love unicorns")
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

Check `lib/box.rei` and `lib/border.rei`.

## Contributing

Take a look at our [Contributing Guide](CONTRIBUTING.md).

### Status

[![Actions Status](https://github.com/davesnx/ocaml-box/workflows/CI/badge.svg)](https://github.com/davesnx/ocaml-box/actions)
