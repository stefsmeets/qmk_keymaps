# Generate keymap svg

cd ../qmk_firmware
qmk c2json | jq . > ../qmk_keymaps/keymap.json

cd ../qmk_keymaps

keymap -c config.yaml parse -q keymap.json -l Base Qwerty Colemak-DH Sym Nav Mouse Function Adjust -c 12 -o keymap.yaml

sed -i s"/LT( SYMBOL, MINS)/{t: '-', h: SYMBOL}/" keymap.yaml
sed -i s"/LT( FUNCTION, ENT)/{t: ENT, h: FUNCTION}/" keymap.yaml
sed -i s"/LT( NAV, END)/{t: END, h: NAV}/" keymap.yaml

keymap -c config.yaml draw keymap.yaml -k splitkb/kyria/rev3 -l LAYOUT_split_3x6_5 -o keymap.svg -s Base Sym Nav Function
