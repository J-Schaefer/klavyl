import sys
sys.path.append("src/klavgen")
# print(sys.path)

import argparse
from dataclasses import dataclass

from klavgen import *

parser = argparse.ArgumentParser()
parser.add_argument("--choc", help="Use Kailh Choc switches", action="store_true")
args = parser.parse_args()

if args.choc:
    print("Using Kailh Choc switches")
else:
    print("Using Cherry MX switches")

# Only changes switch holes & holders to Choc, but keeps MX spacing between keys
use_choc = args.choc

config = Config(
    case_config=CaseConfig(
        side_fillet=4,
        palm_rests_top_fillet=5,
        switch_type=SwitchType.CHOC if use_choc else SwitchType.MX,
    ),
    mx_key_config=MXKeyConfig(case_tile_margin=7.5),
    choc_key_config=ChocKeyConfig(case_tile_margin=7.6),
    controller_config=ControllerConfig(case_tile_margin=5,
                                       item_width=21.5,  # Raspberry Pi Pico, default is Arduino Pro Micro
                                       item_depth=51.6,  # Raspberry Pi Pico, default is Arduino Pro Micro
                                       inner_structure=True),
    trrs_jack_config=TrrsJackConfig(case_tile_margin=5),
    usbc_jack_config=USBCJackConfig(case_tile_margin=5),
)

key_x_gap = MX_KEY_X_SPACING - MX_KEYCAP_1U_WIDTH
key_y_gap = MX_KEY_Y_SPACING - MX_KEYCAP_1U_WIDTH


@dataclass
class Col:
    horz_size: float
    vert_offset: float
    num_rows: int
    horz_offset: float = 0


cols = [
    Col(MX_KEYCAP_1_5U_WIDTH, -1, 4),
    Col(MX_KEYCAP_1U_WIDTH, -3, 4),
    Col(MX_KEYCAP_1U_WIDTH, 4.5, 4, horz_offset=3),
    Col(MX_KEYCAP_1U_WIDTH, 8, 4, horz_offset=1),
    Col(MX_KEYCAP_1U_WIDTH, 3.5, 4),
    Col(MX_KEYCAP_1U_WIDTH, 2, 4),
    Col(MX_KEYCAP_1U_WIDTH, -3, 4),
]

keys = []
x = 0
y = 0
for col in cols:
    y = 0 + col.vert_offset
    x += col.horz_size / 2 + col.horz_offset
    for row_index in range(col.num_rows):
        y -= MX_KEYCAP_1U_WIDTH / 2
        keys.append(Key(x=x, y=y, keycap_width=col.horz_size, keycap_depth=MX_KEYCAP_1U_WIDTH))
        y -= MX_KEYCAP_1U_WIDTH / 2 + key_y_gap
    x += col.horz_size / 2 + key_x_gap

# Thumb cluster
cluster_x = 108
cluster_y = -86

keys.append(Key(x=cluster_x, y=cluster_y, rotate=-25, keycap_width=MX_KEYCAP_1_5U_WIDTH))

second_offset_x = 20
second_offset_y = -12.5
cluster_second_x = cluster_x + second_offset_x
cluster_second_y = cluster_y + second_offset_y
keys.extend(
    [
        Key(
            x=cluster_second_x,
            y=cluster_second_y,
            rotate=-40,
            keycap_depth=MX_KEYCAP_1_5U_WIDTH,
        ),
        Key(
            x=cluster_second_x + MX_KEYCAP_1U_WIDTH + key_x_gap,
            y=cluster_second_y,
            rotate=-40,
            rotate_around=(cluster_second_x, cluster_second_y),
            keycap_depth=MX_KEYCAP_1_5U_WIDTH,
        ),
    ]
)

screw_holes = [  # Clockwise
    ScrewHole(x=2.5, y=8.5, z=0),
    ScrewHole(x=94, y=8.5, z=0),
    ScrewHole(x=172.5, y=8.5, z=0),
    ScrewHole(x=172.5, y=-45.5, z=0),
    ScrewHole(x=141.5, y=-86, z=0),
    ScrewHole(x=143.5, y=-129.5, z=0),
    ScrewHole(x=75, y=-73, z=0),
    ScrewHole(x=2.5, y=-87.7, z=0),
]

patches = [
    Patch(
        points=[
            (-3, 14),
            (178, 14),
            (178, -82),  # horizontal part under controller
            (147, -82),  # horizontal part under controller
            (147, -100),
            (90, -93.2),
            (-3, -93.2),
        ],
        height=config.case_config.case_base_height,
    ),
    Patch(
        points=[
            (140, 14),
            (171.9, 14),
            (171.9, -43.9),
            (140, -43.9),
        ],
        height=config.case_config.case_base_height,
    ),
]

palm_rests = [
    PalmRest(
        points=[
            (-3, -80),
            (120, -80),
            (146.7888827948367, -128.30281581958877),
            (93.34059904202246, -192),
            (-3, -192),
        ],
        height=config.case_config.case_base_height + 8,
        connector_locations_x=[13, 60, 102.5, 134],
    ),
]

texts = [
    # Text(x=16, y=7, z=0, text="v10", font_size=10, extrude=0.4),
    # Text(x=11, y=-102, z=8, text="v10", font_size=10, extrude=0.4)
]

controller = Controller(x=156, y=-10)  # default: Arduino Pro Micro

# trrs_jack = TrrsJack(x=161, y=-51, rotate=-180)

usbc_jack = USBCJack(x=164, y=-82, rotate=-180)
usbc_jack_controller = USBCJack(x=154, y=14)

keyboard_result = render_and_save_keyboard(
    keys=keys,
    screw_holes=screw_holes,
    controller=controller,
    # components=[usbc_jack_controller],
    components=[usbc_jack, usbc_jack_controller],
    # trrs_jack=trrs_jack,
    patches=patches,
    palm_rests=palm_rests,
    texts=texts,
    debug=False,
    render_standard_components=True,
    config=config,
)

print("Done")
