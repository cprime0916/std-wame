data = {"username": "3A.$1Ü2T"}
for var in data["username"]:
    print(hex(ord(var))[2:].upper(), end="")
