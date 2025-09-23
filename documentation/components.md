# Components

This documents provides information about the components used in the design of the Smartie Sorter 3000's mini arcade game enclosure. First, Section 1 provides information about the different types of components used in the design of the Smartie Sorter 3000's mini arcade game enclosure. Thereafter, Section 2 provides information about laser cutting the wooden panels and acrylic components. Finally, Section 3 provides information about the Fusion 360 computer aided design (CAD) files.

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

This section provides information about the wooden components (wooden panels and supports), acrylic components, 3D printed components, and labels.

Information about the electronic components is provided in [electronics.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/electronics.md).

### 1.1. Wooden Components

The wooden components are comprised of medium density fibreboard (MDF) panels and pine supports.

The wooden panels should be laser cut out of:

- 6 mm MDF

Section 2.5 provides more information about laser cutting the wooden panels.

The pine supports should be cut from:

- 12 mm pine
- 21 mm × 21 mm pine

The wooden components should be painted according to the colour scheme provided in [design.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/design.md). The wooden components should then be sealed using a clear coat.

### 1.2. Acrylic Components

Clear acrylic is used for the Name Sign, Smartie Slide, and Sorted Smarties Collector.

The Name Sign should be laser cut out of:

- 6 mm clear acrylic

Section 2.2 provides more information about laser cutting the Name Sign.

The Smartie Slide and Sorted Smarties Collector are assemblies whose panels have been designed to fit together using finger joints.

The Smartie Slide panels and Sorted Smarties Collector panels should be laser cut out of:

- 3 mm transparent acrylic

Section 2.3 and 2.4 provide more information about laser cutting the Smartie Slide panels and Sorted Smarties Collector panels, respectively.

The Smartie Slide and Sorted Smarties Collector should then be assembled by welding their respective panels together using an acrylic cement such as ACRIFIX® 1S 0117. The acrylic cement should be applied using a fine needle and syringe, such as a 0.6&nbsp;mm × 32&nbsp;mm needle and a 1&nbsp;mL syringe.

### 1.3. 3D Printed Components

3D printed components are used for the Colour Detection Mechanism and to house the electronic components.

The 3D printed components should be printed using a 3D printer, such as the Zortrax M300 3D printer, using:

- White PLA filament

Infill settings that maximise the part strength of the 3D printed components should be used.

The 3D printed components should then be glued in place. The structural 3D printed components, such as the Electronics Holder, should be glued using a clear epoxy adhesive such as the Pattex Clear Power Epoxy. The 3D printed components that are involved in the Colour Detection Mechanism should be glued using a cyanoacrylate adhesive such as the Pattex Ultra Gel Super Glue.

### 1.4. Labels

The labels should be printed using a label maker, such as the Brother PT-H110 label maker, using:

- 12 mm black on white laminated tape

The labels should then be affixed in position and sealed using a clear coat.

## 2. Laser Cutting

The outlines of the wooden panels and acrylic components have been exported as DXF files and are available in the [dxf_files](../assets/dxf_files) folder.

These DXF files can be used for laser cutting the wooden panels and acrylic components out of MDF and clear acrylic, respectively.

### 2.1. DXF Files Folder Structure

The folder structure of the dxf_files folder is presented below:

```
.
|__ assets
    |__ dxf_files
        |__ acrylic_components
        |   |__ name_sign
        |   |__ smartie_slide
        |   |__ sorted_smarties_collector
        |__ wooden_panels
```

### 2.2. Name Sign

Laser cut the following DXF file in the [name_sign](../assets/dxf_files/acrylic_components/name_sign) folder out of 6 mm clear acrylic to create the Name Sign:

- 1 × name_sign.dxf

### 2.3. Smartie Slide

Laser cut the following DXF files in the [smartie_slide](../assets/dxf_files/acrylic_components/smartie_slide) folder out of 3 mm clear acrylic to construct the Smartie Slide:

- 1 × back_panel.dxf
- 1 × bottom_panel.dxf
- 1 × front_panel.dxf
- 2 × middle_panel.dxf
- 2 × side_panel.dxf
- 1 × slide_panel.dxf
- 1 × top_panel.dxf

### 2.4. Sorted Smarties Collector

Laser cut the following DXF files in the [sorted_smarties_collector](../assets/dxf_files/acrylic_components/sorted_smarties_collector) folder out of 3 mm clear acrylic to construct the Sorted Smarties Collector:

- 1 × back_panel.dxf
- 3 × divider_bottom.dxf
- 3 × divider_top.dxf
- 1 × front_panel.dxf
- 2 × horizontal_panel.dxf
- 2 × side_panel.dxf
- 1 × top_panel.dxf

### 2.5. Wooden Panels

Laser cut the following DXF files in the [wooden_panels](../assets/dxf_files/wooden_panels) folder out of 6 mm MDF to construct the mini arcade game enclosure:

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
        |   |__ smartie_slide
        |   |__ sorted_smarties_collector
        |__ chocolates
        |   |__ M&Ms
        |   |__ smarties
        |__ connectors
        |__ electronics
        |__ labels      
        |__ supports
        |__ wooden_panels
```
The Smartie Sorter 3000 assembly is available in the fusion_360 folder.

The Colour Detection Mechanism assembly is available in the [assemblies](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360/assemblies) folder.


