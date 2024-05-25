# Generate keymap svg

cd ../../qmk_firmware
qmk c2json | jq . > ../qmk_keymaps/keymap_drawer/keymap.json

cd ../qmk_keymaps/keymap_drawer

keymap -c config.yaml parse -q keymap.json -l Base Qwerty Sym Nav Function Adjust -c 12 -o keymap.yaml

sed -i s"/LT( SYMBOL, BSPC)/{t: 'BSPC', h: SYMBOL}/" keymap.yaml
sed -i s"/LT( FUNCTION, ENT)/{t: ENT, h: FUNCTION}/" keymap.yaml
sed -i s"/LT( NAV, TAB)/{t: TAB, h: NAV}/" keymap.yaml
sed -i s"/TG( FUNCTION)/TG FUNCTION/" keymap.yaml
sed -i s"/MO( ADJUST)/MO ADJUST/" keymap.yaml

keymap -c config.yaml draw keymap.yaml -k splitkb/kyria/rev3 -l LAYOUT_split_3x6_5 -o keymap.svg -s Base Sym Nav Function Adjust
