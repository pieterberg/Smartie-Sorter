# Components

Information about the components used to build the Smartie Sorter 3000 is presented in this document. First, Section 1 provides more information about the different types of components used in the design. Thereafter, Section 2 provides more information about the computer aided design (CAD) files that are provided in the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

### Table of Contents

- [1. Components](#1-components)
  - [1.1. Wooden Components](#11-wooden-components)
  - [1.2. Acrylic Components](#12-acrylic-components)
  - [1.3. 3D Printed Components](#13-3d-printed-components)
  - [1.4. Labels](#14-labels)
- [2. Laser Cutting](#2-laser-cutting)
  - [2.1. DXF Files Folder Structure](#21-dxf-files-folder-structure)
  - [2.2. Name Sign](#22-name-sign)
  - [2.3. Smartie Slide](#23-smartie-slide)
  - [2.4. Sorted Smarties Collector](#24-sorted-smarties-collector)
  - [2.5. Wooden Panels](#25-wooden-panels)
- [3. Fusion 360 Files](#3-fusion-360-files)
  - [3.1. Resources](#31-resources)
  - [3.2. Fusion 360 Folder Structure](#32-fusion-360-folder-structure)

## 1. Components

There are eight different types of components used in the design of the Smartie Sorter 3000, namely: 

1. 3D printed components
2. Acrylic components
3. Chocolates
4. Connectors
5. Electronics
6. Labels
7. Supports
8. Wooden panels

This section provides more information about the wooden components (wooden panels and supports), acrylic components, 3D printed components, and labels.

Information about the electronic components is provided in [electronics.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/electronics.md).

### 1.1. Wooden Components

The wooden components make use of medium density fibreboard (MDF) for the panels and pine for the supports.

DXF files for laser cutting the MDF components are provided in the [wooden_panels](https://github.com/pieterberg/Smartie-Sorter/tree/main/assets/dxf_files/wooden_panels) DXF folder. Using these DXF files, the wooden panels were laser cut from:

- 6 mm MDF

The wooden components were painted according to the colour scheme presented in [design.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/design.md).

The brown colour was achieved using Rust-Oleum Painter's Touch Ultra Cover satin Nutmeg. The white colour was achieved using Rust-Oleum Painter's Touch Ultra Cover flat white. Finally, the white paint was sealed using Rust-Oleum Painter's Touch Ultra Cover satin clear coat.

### 1.2. Acrylic Components

The acrylic component use for the Name Sign was laser cut from:

- 6 mm transparent acrylic

The Unsorted Smarties Holder and the Sorted Smarties Collector were constructed using acrylic panels that fit together using finger joints.

DXF files for laser cutting the acrylic panels are provided in the [unsorted_smarties_holder_finger_joints](https://github.com/pieterberg/Smartie-Sorter/tree/main/assets/dxf_files/unsorted_smarties_holder_finger_joints) and [sorted_smarties_collector_finger_joints](https://github.com/pieterberg/Smartie-Sorter/tree/main/assets/dxf_files/sorted_smarties_collector_finger_joints) DXF folders. Using these DXF files, the acrylic panels were laser cut from: 

- 3 mm transparent acrylic

The acrylic panels were then assembled using acrylic cement.

### 1.3. 3D Printed Components

The mini arcade game enclosure's 3D printed components were printed using a Zortrax M300 3D printer using:

- White PLA filament

### 1.4. Labels

The labels were printed using a Brother PT-H110 label printer using:

- 12 mm black on white laminated tape

The labels were affixed in position and sealed using Rust-Oleum Painter's Touch Ultra Cover satin clear coat.

## 2. Laser Cutting

### 2.1. DXF Files Folder Structure

The folder structure of the dxf_files folder is presented below:

```
.
|__ assets
    |__ dxf_files
        |__ acrylic_components
            |__ name_sign
            |__ smartie_slide
            |__ sorted_smarties_collector
        |__ wooden_panels
```

### 2.2. Name Sign

To create the Name Sign, laser cut the following DXF files out of 6 mm clear acrylic:

- 1 × name_sign.dxf

### 2.3. Smartie Slide

To create the Smartie Slide, laser cut the following DXF files out of 3 mm clear acrylic:

- 1 × back_panel.dxf
- 1 × bottom_panel.dxf
- 1 × front_panel.dxf
- 2 × middle_panel.dxf
- 2 × side_panel.dxf
- 1 × slide_panel.dxf
- 1 × top_panel.dxf

### 2.4. Sorted Smarties Collector

To create the Sorted Smarties Collector, laser cut the following DXF files out of 3 mm clear acrylic:

- 1 × back_panel.dxf
- 3 × divider_bottom.dxf
- 3 × divider_top.dxf
- 1 × front_panel.dxf
- 2 × horizontal_panel.dxf
- 2 × side_panel.dxf
- 1 × top_panel.dxf

### 2.5. Wooden Panels

To construct the Mini Arcade-Game Enclosure, laser cut the following DXF files out of 6 mm MDF:

- 1 × back_panel.dxf
- 1 × back_panel_tolerances.dxf
- 1 × base_plate.dxf
- 1 × bottom_access_panel_tolerances.dxf
- 1 × colour_detection_mechanism_top_panel.dxf
- 1 × control_panel_bottom.dxf
- 1 × control_panel_front.dxf
- 1 × control_panel_top.dxf
- 1 × front_panel.dxf
- 1 × name_sign_bottom_panel.dxf
- 2 × side_panel.dxf
- 1 × sorted_smarties_cover.dxf
- 1 × sorted_smarties_top.dxf
- 1 × top_access_panel.dxf
- 1 × top_access_panel_tolerances.dxf
- 1 × top_panel.dxf
- 1 × unsorted_smarties_back.dxf
- 1 × unsorted_smarties_top.dxf

## 3. Fusion 360 Files

All components, mechanisms, and assemblies were designed and modelled using Fusion 360.

The CAD files have been exported and are available in the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

### 3.1. Resources

The following Fusion 360 files are available in the fusion_360 folder:

- Fusion 360 archive files (.f3d) of the components
- Fusion 360 archive file (.f3z) of the Colour Detection Mechanism
- Fusion 360 archive file (.f3z) of the Smartie Sorter

### 3.2. Fusion 360 Folder Structure

The folder structure of the fusion_360 folder is presented below:

```
.
|__ fusion_360
    |__ assemblies
    |__ components
        |__ 3d_printed_components
        |__ acrylic_components
            |__ smartie_slide
            |__ sorted_smarties_collector
        |__ chocolates
            |__ M&Ms
            |__ smarties
        |__ connectors
        |__ electronics
        |__ labels      
        |__ supports
        |__ wooden_panels
```
The Smartie Sorter 3000 assembly is available in the fusion_360 folder.

The Colour Detection Mechanism assembly is available in the [assemblies](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360/assemblies) folder.


