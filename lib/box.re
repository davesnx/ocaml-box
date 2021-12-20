open Lib;
open Border;

type position = [ | `Left | `Center | `Right];

let render = (~align=`Center, ~float=`Left, ~padding=Padding.empty, ~margin=Margin.empty, ~border=Round, text) => {
  let symbols = Border.symbols(border);
  let columns = Terminal.columns();
  let bordersWidth = 2;

  let paddingLeftValue = padding.left + bordersWidth;
  let paddingLeft = renderEmpty(paddingLeftValue);

  let marginTop = repeat(margin.top, newLine);
  let marginBottom = repeat(margin.bottom, newLine);

  let contentWidth = calculateWidestLine(text) + paddingLeftValue * 2;
  let horitzontalTop = repeat(contentWidth, symbols.top);
  let horitzontalBottom = repeat(contentWidth, symbols.bottom);

  let calculateMarginLeft = (~columns as _, value) => {
    switch (float) {
      | `Left => value * 2
      | `Center => contentWidth - value * 2
      | `Right => (contentWidth * 2) - value * 2
    }
  };

  let marginLeftValue = calculateMarginLeft(~columns, margin.left);
  let marginLeft = renderEmpty(marginLeftValue);

  let renderLine = (text) => {
    let paddingRightValue =
      contentWidth - textLength(text) - padding.right - bordersWidth;
    let paddingRight = renderEmpty(paddingRightValue);
    let text = stack([paddingLeft, text, paddingRight]);
    stack(
      [marginLeft, symbols.left, text, symbols.right],
    );
  };

  let renderContent = (text) => {
    let widestLine = calculateWidestLine(text);
    let lines = splitLines(text);
    switch (align) {
      | `Left => lines |> List.map(renderLine);
      | `Right => {
        lines |> List.map((line) => {
          let padLeft = widestLine - textLength(line);
          let left = repeat(padLeft, " ");
          stack([left, line]) |> renderLine;
        });
      }
      | `Center => {
        lines |> List.map((line) => {
          let padRight = (widestLine - textLength(line)) / 2;
          let left = repeat(padRight, " ");
          stack([left, line]) |> renderLine;
        });
      }
    }
  };

  let content = renderContent(text) |> row;
  let paddingTop = repeat(~between=newLine, padding.top, renderLine(""));
  let paddingBottom = repeat(~between=newLine, padding.bottom, renderLine(""));

  let header =
    stack(
      [
        marginTop,
        marginLeft,
        symbols.topLeft,
        horitzontalTop,
        symbols.topRight,
      ],
    );

  let body = switch (padding) {
    | { top: 0, bottom: 0, _ } => content
    | { top: 0, _ } => row([content, paddingBottom])
    | { bottom: 0, _ } => row([paddingTop, content])
    | _ => row([paddingTop, content, paddingBottom])
  };

  let footer =
    stack(
      [
        marginLeft,
        symbols.bottomLeft,
        horitzontalBottom,
        symbols.bottomRight,
        marginBottom,
      ],
    );

  row([header, body, footer]);
};
