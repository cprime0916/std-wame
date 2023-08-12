## TurnBase
def hex_change(bit):
    if 65 <= ord(bit) <= 70:
        return ord(bit) - 55
    else:
        return int(bit)
def hex_converter(byte):
    length = len(byte)
    value = 0
    for i in range(length):
        value += hex_change(byte[-i+1]) * pow(16, i)
    return value

## First 16-bit is username (8-char)
username = ""
data = "33412E2431DC3254"
username_data = data[:16]
for i in range(0, 15, 2):
    byte = data[i]+data[i+1]
    username += chr(hex_converter(byte))

print(username)
