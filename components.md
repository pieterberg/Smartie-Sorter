# Components

The computer-aided design (CAD) aspects of the Smartie Sorter 3000's mini arcade game enclosure are presented in this document. First, Section 1 looks at the physical materials that the Smartie Sorter 3000's mini arcade game enclosure's components are made from. Then, Section 2 lists the available resources for the Smartie Sorter 3000's mini arcade game enclosure. Finaly, Section 3 outlines the folder structure of the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

All components were designed and modelled using Fusion 360.

### Table of Contents

- [1. Components](#1-components)
  - [1.1. Wooden Components](#11-wooden-components)
  - [1.2. Acrylic Components](#12-acrylic-components)
  - [1.3. 3D Printed Components](#13-3d-printed-components)
  - [1.4. Labels](#14-labels)
- [2. Resources](#2-resources)
- [3. Folder Structure](#3-folder-structure)

## 1. Components

The Smartie Sorter 3000's mini arcade game enclosure was designed using Fusion 360. There are three different types of components used in the design, namely wooden components, acrylic components, and 3D printed components.

Information about the [electronic](https://github.com/pieterberg/Smartie-Sorter/blob/main/electronics.md) components is provided in a separate document.

### 1.1. Wooden Components

The wooden components consist of medium density fiberboard (MDF) components for the enclosure's panels and pine for the enclosure's supports.

DXF files for laser cutting the MDF components are provided in the [dxf_files](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/dxf_files) folder. Using these DXF files, the Smartie Sorter 3000's enclosure's panels were laser cut from:

- 6 mm MDF

### 1.2. Acrylic Components

The different panels that make up the acrylic components were designed to fit together using finger joints. The [acrylic_components](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360/components/acrylic_components) folder provides both the overall models and the finger joint versions of the Unsorted Smarties Holder and the Sorted Smarties Collector. Once designed, the acrylic components were laser cut from either:

- 3 mm transparent acrylic
- or 6 mm transparent acrylic

### 1.3. 3D Printed Components

The 3D printed components were printed using a Zortrax M300 3D printer using:

- White PLA filament

### 1.4. Labels

The labels were printed using a Brother PT-H110 Label Printer using:

- 12 mm black on white laminated tape

The labels were affixed in position and sealed using a Rust-Oleum satin clear coat.

## 2. Resources

The following Fusion 360 files are available in the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder:

- Fusion 360 archive files (.f3d) of the components
- Fusion 360 archive file (.f3z) of the Colour Detection Mechanism
- Fusion 360 archive file (.f3z) of the Smartie Sorter

## 3. Folder Structure

The folder structure of the [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder is presented below:

```
.
|__ fusion_360
    |__ assemblies
    |__ components
        |__ 3d_printed_components
        |__ acrylic_components
        |__ chocolates
            |__ M&Ms
            |__ smarties
        |__ connectors
        |__ electronics
        |__ labels      
        |__ supports
        |__ wooden_components
```
The Smartie Sorter 3000 assembly is available in the top-level [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder.

The Colour Detection Mechanism assembly is available in the [assemblies](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360/assemblies) folder.


