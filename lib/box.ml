open Terminal

type position = Left | Center | Right

let render ?(align = Center) ?(float = Left) ?(padding = Padding.empty)
    ?(margin = Margin.empty) ?(border = Border.Round) text =
  let symbols = Border.symbols border in
  let columns = Terminal.columns () in
  let paddingLeftValue = padding.left in
  let paddingLeft = renderSpace paddingLeftValue in
  let marginTop = repeat margin.top newLine in
  let marginBottom = repeat margin.bottom newLine in
  let paddingRightValueWithoutText = padding.right in
  let contentWidth =
    calculateWidestLine text + paddingLeftValue + paddingRightValueWithoutText
  in
  let horitzontalTop = repeat contentWidth symbols.top in
  let horitzontalBottom = repeat contentWidth symbols.bottom in
  let calculateMarginLeft ~columns:_ value =
    match float with
    | Left -> value * 2
    | Center -> contentWidth - (value * 2)
    | Right -> (contentWidth * 2) - (value * 2)
  in
  let marginLeftValue = calculateMarginLeft ~columns margin.left in
  let marginLeft = renderSpace marginLeftValue in
  let renderLine text =
    let paddingRightValue = contentWidth - textLength text - padding.left in
    let paddingRight = renderSpace paddingRightValue in
    let text = stack [ paddingLeft; text; paddingRight ] in
    stack [ marginLeft; symbols.left; text; symbols.right ]
  in
  let renderContent text =
    let widestLine = calculateWidestLine text in
    let lines = splitLines text in
    match align with
    | Left -> lines |> List.map renderLine
    | Right ->
        lines
        |> List.map (fun line ->
               let padLeft = widestLine - textLength line in
               let left = repeat padLeft " " in
               stack [ left; line ] |> renderLine)
    | Center ->
        lines
        |> List.map (fun line ->
               let padRight = (widestLine - textLength line) / 2 in
               let left = repeat padRight " " in
               stack [ left; line ] |> renderLine)
  in
  let content = renderContent text |> row in
  let paddingTop = repeat ~between:newLine padding.top (renderLine "") in
  let paddingBottom = repeat ~between:newLine padding.bottom (renderLine "") in
  let header =
    stack
      [
        marginTop; marginLeft; symbols.topLeft; horitzontalTop; symbols.topRight;
      ]
  in
  let body =
    match padding with
    | { top = 0; bottom = 0; _ } -> content
    | { top = 0; _ } -> row [ content; paddingBottom ]
    | { bottom = 0; _ } -> row [ paddingTop; content ]
    | _ -> row [ paddingTop; content; paddingBottom ]
  in
  let footer =
    stack
      [
        marginLeft;
        symbols.bottomLeft;
        horitzontalBottom;
        symbols.bottomRight;
        marginBottom;
      ]
  in
  row [ header; body; footer ]

module Border = Border
module Padding = Padding
module Margin = Margin
