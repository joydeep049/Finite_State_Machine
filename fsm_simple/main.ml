let my_main() =
    let str = "abaabbbb" in
    let str_lst = List.of_seq (String.to_seq str) in
    match (process (Start:state) str_lst) with
        | Some final_state ->
        let final_list = [A_Start ; End] in
        if is_accepting final_list final_state then
            print_endline "Accepted"
        else
            print_endline "Not Accepted"
        | None -> print_endline "Invalid Input or Transition"