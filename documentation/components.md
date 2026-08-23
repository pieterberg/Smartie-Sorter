# Components

This documents provides information about the components used in the design of the Smartie Sorter 3000's mini arcade game enclosure. First, Section 1 provides information about the different types of components used in the design of the Smartie Sorter 3000's mini arcade game enclosure. Thereafter, Section 2 provides information about manufacturing the acrylic components, stainless steel components, supports, and wooden panels. Finally, Section 3 provides information about the Fusion 360 computer aided design (CAD) files.

### Table of Contents

- [1. Components](#1-components)
  - [1.1. Wooden Components](#11-wooden-components)
  - [1.2. Acrylic Components](#12-acrylic-components)
  - [1.3. 3D Printed Components](#13-3d-printed-components)
  - [1.4. Labels](#14-labels)
  - [1.5. Connectors](#15-connectors)
- [2. Manufacturing](#2-manufacturing)
  - [2.1. Manufacturing Folder Structure](#21-manufacturing-folder-structure)
  - [2.2. Wooden Panels](#22-wooden-panels)
  - [2.3. Supports](#23-supports)
  - [2.4. Acrylic Components](#24-acrylic-components)
- [3. Fusion 360 Files](#3-fusion-360-files)
  - [3.1. Resources](#31-resources)
  - [3.2. Fusion 360 Folder Structure](#32-fusion-360-folder-structure)

## 1. Components

There are ten different types of components used in the design of the Smartie Sorter 3000, namely: 

1. 3D printed components
2. Acrylic components
3. Chocolates
4. Connectors
5. Electronics
6. Fasteners
7. Labels
8. Stainless steel components
9. Supports
10. Wooden panels

This section provides information about the wooden components (wooden panels and supports), acrylic components, 3D printed components, and labels.

Information about the electronic components is provided in [electronics.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/electronics.md).

### 1.1. Wooden Components

The wooden components are comprised of medium density fibreboard (MDF) panels and pine supports.

The wooden panels should be laser cut out of:

- 6 mm MDF

Section 2.1 provides more information about laser cutting the wooden panels.

The pine supports should be cut from:

- 12 mm pine
- 21 mm × 21 mm pine

The wooden components should be painted according to the colour scheme provided in [design.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/design.md). The wooden components should then be sealed using a clear coat.

### 1.2. Acrylic Components

Clear acrylic is used for the Name Sign, Smartie Slide, and Sorted Smarties Collector.

The Name Sign should be laser cut out of:

- 6 mm clear acrylic

The Smartie Slide and Sorted Smarties Collector are assemblies whose panels have been designed to fit together using finger joints.

The Smartie Slide panels and Sorted Smarties Collector panels should be laser cut out of:

- 3 mm transparent acrylic

Section 2.4 provides more information about laser cutting the Name Sign, Smartie Slide panels, and Sorted Smarties Collector panels.

The Smartie Slide and Sorted Smarties Collector should then be assembled by welding their respective panels together using an acrylic cement such as ACRIFIX® 1S 0117. The acrylic cement should be applied using a fine needle and syringe, such as a 0.6&nbsp;mm × 32&nbsp;mm needle and a 1&nbsp;mL syringe.

### 1.3. 3D Printed Components

3D printed components are used for the Colour Detection Mechanism and to house the electronic components.

The 3D printed components should be printed using a 3D printer, such as the Bambu Lab X1 Series 3D printer, using:

- White PLA filament

A layer height of 0.16 mm should be used for a high print quality.

An infill setting of 35% should be used to maximise the strength of the 3D printed components while minimizing their weight.

The Smartie Hopper has a 10° slant on its front face which should be used as the bottom face when 3D printing the Smartie Hopper.

The 3D printed components should then be glued in place. The structural 3D printed components, such as the Electronics Holder, should be glued using a clear epoxy adhesive such as the Pattex Clear Power Epoxy. The Servo Horn should also be glued to the Smartie Arm using the clear epoxy adhesive.

The 3D printed components that are involved in the Colour Detection Mechanism should be glued using a cyanoacrylate adhesive such as the Pattex Ultra Gel Super Glue.

### 1.4. Labels

The labels should be printed using a label maker, such as the Brother PT-H110 label maker, using:

- 12 mm black on white laminated tape

The labels should then be affixed in position and sealed using a clear coat.

### 1.5. Connectors

Neodymium disc magnets are used to connect the removable components. The magnets should be glued in place using a cyanoacrylate adhesive such as the Pattex Ultra Gel Super Glue.

It is important to ensure that the polarities of the corresponding magnets line up before gluing them in place. This can be achieved by first gluing a single magnet in place on one side. This magnet can then be used to get the orientation of the corresponding magnet on the opposite side, which can then be glued in place. All of the other magnets can then be glued using these two reference magnets.

## 2. Manufacturing

The outlines of the wooden panels, supports, acrylic components, and stainless steel components have been exported as DXF files and are available in the [dxf_files](../manufacturing/dxf_files) folder. These DXF files can be used for laser cutting the different components out of their respective materials.

Drawings to facilitate the machining of the angled features for the name sign at the top of the mini arcade game enclosure are available in the [drawings](../manufacturing/drawings) folder.

### 2.1. Manufacturing Folder Structure

The folder structure of the manufacturing folder is presented below:

```
.
|__ manufacturing
    |__ drawings
    |   |__ acrylic_components
    |   |__ stainless_steel_components
    |   |__ wooden_panels
    |__ dxf_files
        |__ acrylic_components
        |   |__ name_sign
        |   |__ smartie_slide
        |   |__ sorted_smarties_collector
        |__ stainless_steel_components
        |__ supports
        |__ wooden_panels
```

### 2.2. Wooden Panels

Laser cut the following DXF files in the [wooden_panels](../manufacturing/dxf_files/wooden_panels) folder out of 6 mm MDF to construct the mini arcade game enclosure:

- 1 × back_panel.dxf
- 1 × base_plate.dxf
- 1 × bottom_access_panel.dxf
- 1 × colour_detection_mechanism_top_panel.dxf
- 1 × control_panel_bottom.dxf
- 1 × control_panel_front.dxf
- 1 × control_panel_top.dxf
- 1 × front_panel.dxf
- 1 × name_sign_bottom_panel.dxf
- 2 × side_panel.dxf
- 1 × sorted_smarties_cover.dxf
- 1 × sorted_smarties_top_panel.dxf
- 1 × top_access_panel.dxf
- 1 × top_panel.dxf
- 1 × unsorted_smarties_back_panel.dxf
- 1 × unsorted_smarties_top_panel.dxf

Afterwards, slopes for the name sign need to be added to the Back Panel, Name Sign Bottom Panel, and Top Panel. These slopes should be added according to the following drawings:

- [DWG_1001_back_panel](../manufacturing/drawings/wooden_panels/DWG_1001_back_panel.pdf)
- [DWG_1002_name_sign_bottom_panel](../manufacturing/drawings/wooden_panels/DWG_1002_name_sign_bottom_panel.pdf)
- [DWG_1003_top_panel](../manufacturing/drawings/wooden_panels/DWG_1003_top_panel.pdf)

### 2.3. Supports

Laser cut the following DXF files in the [supports](../manufacturing/dxf_files/supports) folder out of 12 mm pine to construct the mini arcade game enclosure:

- 2 × base_plate_support.dxf
- 2 × control_panel_support.dxf 
- 1 × name_sign_support_left.dxf
- 1 × name_sign_support_right.dxf
- 1 × smartie_feed_support.dxf

The following supports should be cut from 21 mm x 21 mm pine:

| Quantity | Component                         | Length (mm) |
|:--------:|-----------------------------------|------------:|
|    1x    | Back Panel Support Left           |       478.6 |
|    1x    | Back Panel Support Right          |       270.0 |
|    1x    | Back Panel Support Middle         |       249.0 |
|    1x    | Back Panel Support Bottom         |       228.0 |
|    1x    | Sorted Smarties Top Support Left  |       142.0 |
|    1x    | Sorted Smarties Top Support Right |        28.0 |

### 2.4. Acrylic Components

Laser cut the following DXF file in the [name_sign](../manufacturing/dxf_files/acrylic_components/name_sign) folder out of 6 mm clear acrylic to create the Name Sign:

- 1 × name_sign.dxf

Afterwards, the slopes at the top and bottom of the Name Sign component need to be added according to [DWG_201_name_sign](../manufacturing/drawings/acrylic_components/DWG_201_name_sign.pdf).

Laser cut the following DXF files in the [smartie_slide](../manufacturing/dxf_files/acrylic_components/smartie_slide) folder out of 3 mm clear acrylic to construct the Smartie Slide:

- 1 × back_panel.dxf
- 1 × bottom_panel.dxf
- 1 × front_panel.dxf
- 2 × middle_panel.dxf
- 2 × side_panel.dxf
- 1 × slide_panel.dxf
- 1 × top_panel.dxf

Laser cut the following DXF files in the [sorted_smarties_collector](../manufacturing/dxf_files/acrylic_components/sorted_smarties_collector) folder out of 3 mm clear acrylic to construct the Sorted Smarties Collector:

- 1 × back_panel.dxf
- 3 × divider_bottom.dxf
- 3 × divider_top.dxf
- 1 × front_panel.dxf
- 2 × horizontal_panel.dxf
- 2 × side_panel.dxf
- 1 × top_panel.dxf

## 3. Fusion 360 Files

All components, mechanisms, and assemblies were designed and modelled using Fusion 360.

The CAD files have been exported and are available in the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

### 3.1. Resources

The following Fusion 360 files are available in the fusion_360 folder:

- Fusion 360 archive files (.f3d) of the components
- Fusion 360 archive file (.f3z) of the Colour Detection Mechanism assembly
- Fusion 360 archive file (.f3z) of the Smartie Hopper assembly
- Fusion 360 archive file (.f3z) of the Smartie Sorter assembly

### 3.2. Fusion 360 Folder Structure

The folder structure of the fusion_360 folder is presented below:

```
.
|__ fusion_360
    |__ assemblies
    |__ components
        |__ 3d_printed_components
        |   |__ colour_sensor_holder
        |   |__ colour_sensor_servo_seat
        |   |__ name_sign_LED_holder_top
        |__ acrylic_components
        |   |__ smartie_slide
        |   |__ sorted_smarties_collector
        |__ chocolates
        |   |__ M&Ms
        |   |__ smarties
        |__ connectors
        |__ electronics
        |   |__ servo_horns
        |__ fasteners
        |__ labels
        |__ stainless_steel_components      
        |__ supports
        |__ wooden_panels
```
The Smartie Sorter 3000 assembly is available in the fusion_360 folder.

The Colour Detection Mechanism and Smartie Hopper assemblies are available in the [assemblies](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360/assemblies) folder.


