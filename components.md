# Components

The computer-aided design (CAD) aspects of the Smartie Sorter 3000's mini arcade game enclosure are presented in this document. First, Section 1 looks at the physical materials that the wooden, acrylic, and 3D printed components are made from. Then, Section 2 lists the available resources for the Smartie Sorter 3000's mini arcade game enclosure Finaly, Section 3 outlines the folder structure of the [components](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/components) documentation folder.

All components were designed and modelled using Fusion 360.

### Table of Contents

- [1. Components](#1-components)
- [2. Resources](#2-resources)
- [3. Folder Structure](#3-folder-structure)

## 1. Components

The Smartie Sorter 3000's mini arcade game enclosure was designed using Fusion 360. There are three different types of components used in the design, namely wooden components, acrylic components, and 3D printed components. The wooden components consist of medium density fiberboard (MDF) components for the enclosure's panels, and pine for the enclosure's supports.

DXF files for laser cutting the MDF components are provided in the [dxf_files](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/components/dxf_files) folder. Using these DXF files, the Smartie Sorter 3000's enclosure's panels were laser cut from:

- 6 mm MDF

The different panels that make up the acrylic components were designed to fit together using finger joints. The [acrylic_components](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/components/fusion_360_files/components/acrylic_components) folder provides both the overall models and the finger joint versionsof the Unsorted Smarties Holder and the Sorted Smarties Collector. Once designed, the acrylic components were laser cut from either:

- 3 mm transparent acrylic
- or 6 mm transparent acrylic

The 3D printed components were printed using a Zortrax M300 3D printer using:

- White PLA filament

## 2. Resources

The documentation foler contains the following resources:

- Fusion 360 archive files (.f3d) of all the components
- Fusion 360 archive files (.f3z) of the Smartie Sorter assemblies
- DXF files (.dxf) to use for laser cutting the wooden components

## 3. Folder Structure

The components folder structure:

```
.
|__ components
    |__ dxf_files
    |__ fusion_360_files
        |__ assemblies
        |__ components
            |__ 3d_printed_components
            |__ acrylic_components
            |__ chocolates
                |__ M&Ms
                |__ smarties
            |__ connectors
            |__ electronics
            |__ supports
            |__ wooden_components
```

The main [fusion_360_files](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/components/fusion_360_files) project folder contains the final Smartie Sorter assembly. The [assemblies](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/components/fusion_360_files/assemblies) folder contains the proposed Smartie Colour Detection mechanism assembly.


