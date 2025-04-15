# Components

Information about the components used to build the Smartie Sorter 3000 is presented in this document. First, Section 1 provides more information about the different types of components used in the design. Thereafter, Section 2 provides more information about the computer aided design (CAD) files that are provided in the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

### Table of Contents

- [1. Components](#1-components)
  - [1.1. Wooden Components](#11-wooden-components)
  - [1.2. Acrylic Components](#12-acrylic-components)
  - [1.3. 3D Printed Components](#13-3d-printed-components)
  - [1.4. Labels](#14-labels)
- [2. Fusion 360 Files](#2-fusion-360-files)
  - [2.1. Resources](#21-resources)
  - [2.2. Folder Structure](#22-folder-structure)

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

Information about the [electronic](https://github.com/pieterberg/Smartie-Sorter/blob/main/electronics.md) components is provided in a separate document.

### 1.1. Wooden Components

The wooden components make use of medium density fiberboard (MDF) for the panels and pine for the supports.

DXF files for laser cutting the MDF components are provided in the [wooden_panels](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/dxf_files/wooden_panels) DXF folder. Using these DXF files, the wooden panels were laser cut from:

- 6 mm MDF

The woodem components were painted according to the colour scheme presented in [design.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/design.md).

The brown colour was achieved using Rust-Oleum Painter's Touch Ultra Cover satin Nutmeg. The white colour was achieved using Rust-Oleum Painter's Touch Ultra Cover flat white. Finally, the white paint was sealed using Rust-Oleum Painter's Touch Ultra Cover satin clear coat.

### 1.2. Acrylic Components

The acrylic component use for the Name Sign was laser cut from:

- 6 mm transparent acrylic

The Unsorted Smarties Holder and the Sorted Smarties Collector were constructed using acrylic panels that fit together using finger joints.

DXF files for laser cutting the acrylic panels are provided in the [unsorted_smarties_holder_finger_joints](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/dxf_files/unsorted_smarties_holder_finger_joints) and [sorted_smarties_collector_finger_joints](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/dxf_files/sorted_smarties_collector_finger_joints) DXF folders. Using these DXF files, the acrylic panels were laser cut from: 

- 3 mm transparent acrylic

The acrylic panels were then assembled using acrylic cement.

### 1.3. 3D Printed Components

The 3D printed components were printed using a Zortrax M300 3D printer using:

- White PLA filament

### 1.4. Labels

The labels were printed using a Brother PT-H110 label printer using:

- 12 mm black on white laminated tape

The labels were affixed in position and sealed using Rust-Oleum Painter's Touch Ultra Cover satin clear coat.

## 2. Fusion 360 Files

All components, mechanisms, and assemblies were designed and modelled using Fusion 360.

The CAD files have been exported and are available in the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

### 2.1. Resources

The following Fusion 360 files are available in the fusion_360 folder:

- Fusion 360 archive files (.f3d) of the components
- Fusion 360 archive file (.f3z) of the Colour Detection Mechanism
- Fusion 360 archive file (.f3z) of the Smartie Sorter

### 2.2. Folder Structure

The folder structure of the fusion_360 folder is presented below:

```
.
|__ fusion_360
    |__ assemblies
    |__ components
        |__ 3d_printed_components
        |__ acrylic_components
            |__ sorted_smarties_collector_finger_joints
            |__ unsorted_smarties_holder_finger_joints
        |__ chocolates
            |__ M&Ms
            |__ smarties
        |__ connectors
        |__ electronics
        |__ labels      
        |__ supports
        |__ wooden_panels
```
The Smartie Sorter 3000 assembly is available in the top-level of the fusion_360 folder.

The Colour Detection Mechanism assembly is available in the [assemblies](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360/assemblies) folder.


