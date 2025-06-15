# Generate keymap svg

cd ../../qmk_firmware
qmk c2json | jq . > ../qmk_keymaps/keymap_drawer/keymap.json

cd ../qmk_keymaps/keymap_drawer

keymap -c config.yaml parse -q keymap.json -l Base Qwerty Sym Nav Function -c 12 -o keymap.yaml

sed -i \
       -e s"/LT( SYMBOL, MINS)/{t: '-', h: SYMBOL}/" \
       -e s"/LT( FUNCTION,ENT)/{t: ENT, h: FUNCTION}/" \
       -e s"/LT( FUNCTION,F1)/{t: 'F1', h: FUNCTION}/"  \
       -e s"/'LT( FUNCTION,ESC)'/{t: ESC, h: FUNCTION}/"  \
       -e s"/LT( SYMBOL,HOME)/{t: 'HOME', h: SYMBOL}/"  \
       -e s"/LT( NAV,EQL)/{t: '=', h: NAV}/"  \
       -e s"/LT( NAV,END)/{t: 'END', h: NAV}/"  \
       -e s"/TG( FUNCTION)/TG FUNCTION/" \
       -e s"/MO( ADJUST)/MO ADJUST/" \
       -e s"/MO( SYMBOL)/MO SYMBOL/" \
       -e s"/MO( NAV)/MO NAV/" \
       -e s"/DF( QWERTY)/DF QWERTY/" \
       -e s"/DF( BASE)/DF BASE/" \
       -e s"/MOD_LSFT/LSFT/" \
       -e s"/MOD_RSFT/RSFT/" \
       -e s"/UM(E11)/👍/" \
       -e s"/UM(E12)/🎉/" \
       -e s"/UM(E13)/🚀/" \
       -e s"/UM(E14)/💪/" \
       -e s"/UM(E15)/👊/" \
       -e s"/UM(E16)/👋/" \
       -e s"/UM(E21)/🤣/" \
       -e s"/UM(E22)/😁/" \
       -e s"/UM(E23)/😅/" \
       -e s"/UM(E24)/😬/" \
       -e s"/UM(E25)/🤓/" \
       -e s"/UM(E26)/😱/" \
       -e s"/UM(E31)/👎/" \
       -e s"/UM(E32)/🧐/" \
       -e s"/UM(E33)/🫣/" \
       -e s"/UM(E34)/🤯/" \
       -e s"/UM(E35)/🤔/" \
       -e s"/UM(E36)/😭/" \
       keymap.yaml

keymap -c config.yaml draw keymap.yaml -k splitkb/kyria/rev3 -l LAYOUT_split_3x6_5 -o keymap.svg -s Base Sym Nav Function
