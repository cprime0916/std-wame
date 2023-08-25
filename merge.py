mode = None
cmd = "/merge_2"
recipes = {
    1: ["Pancake", [["flour", 5], ["milk", 3], ["egg", 2]]],
    2: ["Soup", [["water", 10], ["fish", 1], ["salt", 2]]]
}
if cmd == "/merge_mode":
    mode = "merge"
elif cmd == "/recipe":
    recipe_keys = recipes.keys()
    for var in recipe_keys:
        print(f"{var} -- {recipes[var][0]}")
elif cmd[:7] == "/merge_":
    materials = [var[0] for var in recipes[int(cmd[7:])][1]]
    amounts = [var[1] for var in recipes[int(cmd[7:])][1]]
    for i in range(len(materials)):
        item_bag[materials[i]] -= amounts[i]
    print(materials)
