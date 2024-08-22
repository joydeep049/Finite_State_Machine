let is_accepting (final_list : state list) (s:state) =
    List.mem s final_list

let char_to_event (c:char) : event option =
    match c with
        | 'a' -> Some A
        | 'b' -> Some B
        |  _  -> None