# ocaml-box

```

    ╭─────────────────────────────────────────────────╮
    │                                                 │
    │   Render those kinds of boxes in the terminal   │
    │                                                 │
    ╰─────────────────────────────────────────────────╯

```
Render boxes in the terminal with OCaml / Reason.
Port of https://github.com/sindresorhus/boxen.

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

### Using opam (not available in opam yet)

```bash
opam install ocaml-box
```

### Using npm

```bash
yarn global add ocaml-box
# or
npm -g install ocaml-box
```

## Usage

It can be used in OCaml / Reason

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

[![Actions Status](https://github.com/davesnx/ocaml-box/workflows/CI/badge.svg)](https://github.com/davesnx/ocaml-box/actions)
[![NPM Version](https://badge.fury.io/js/%40davesnx%2Focaml-box.svg)](https://badge.fury.io/js/%40davesnx%2Focaml-box)
