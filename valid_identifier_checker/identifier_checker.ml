type state = Start | Valid | Invalid

type event = Letter | Digit | Special | InvalidChar

let transition (s : state) (e : event) : state =
    match (s, e) with
    | (Start, Letter) -> Valid
    | (Start, _) -> Invalid
    | (Valid, Letter) -> Valid
    | (Valid, Digit) -> Valid
    | (Valid, Special) -> Valid
    | (Valid, InvalidChar) -> Invalid
    | _ -> Invalid

let is_letter c =
    match c with
    | 'a' .. 'z' | 'A' .. 'Z' -> true
    | _ -> false

let is_digit c =
    match c with
    | '0' .. '9' -> true
    | _ -> false

let is_special c =
    match c with
    | '_' | '@' | '#' | '$' | '&' -> true
    | _ -> false

let char_to_event c =
    if is_letter c then Letter
    else if is_digit c then Digit
    else if is_special c then Special
    else InvalidChar

let process (s : state) str =
    let rec aux s = function
        | [] -> s
        | hd :: tl -> aux (transition s (char_to_event hd)) tl
    in
    aux s (List.of_seq (String.to_seq str))

let mymain() =
    print_endline "Enter a string:";
    let str = input_line stdin in
    let final_state = process Start str in
    if final_state = Valid then
        print_endline "Valid Identifier"
    else
        print_endline "Invalid Identifier"
