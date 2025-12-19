# Replacing the Mannequin with a MetaHuman

**Unreal Engine 5.7 – Animation & Retargeting Guide**

Source tutorial:  
https://www.youtube.com/watch?v=wJKrIHWRTco

---

## Overview

This guide summarizes the process of replacing the default UE mannequin with a MetaHuman character in **Unreal Engine 5.7**, including animation retargeting, IK setup, foot IK control rigs, and component hierarchy fixes.

---

## 1. Importing the MetaHuman

### Add MetaHuman to Project

- Open **Quixel Bridge** inside Unreal Engine.
- Go to the **MetaHumans** tab.
- Click **Add** on your chosen MetaHuman (e.g., _Ada_).  
  _(~00:00:10)_

### Enable Required Plugins

- On first import, Unreal will prompt you to enable required plugins.
- Enable all MetaHuman-related plugins.
- Restart the editor to apply changes.  
  _(~00:00:40)_

---

## 2. Rigging and Skeleton Setup

### Identify the MetaHuman Skeletal Mesh

- Open the MetaHuman **Blueprint**.
- Locate the body skeletal mesh (e.g., _Female Medium Normal Weight Body_).
- This mesh is the target for animation retargeting.  
  _(~00:02:30)_

### Fix IK Retargeter Bone Chain Warning

**Warning:**

> “IK retargeter bone chain, Root, was unable to be normalized. Chain too short.”

**Fix:**

1. Autogenerate the retargeter.
2. Export the retarget assets.
3. Open both **Source** and **Target IK Rigs**.
4. Delete the existing **Root** retarget chain.
5. Create a new **Root** chain on both rigs.
6. Save both rigs.
7. Use the exported retargeter instead of autogenerating again.  
   _(~00:06:00)_

---

## 3. Copying and Adding IK Bones

### Why This Is Needed

- MetaHuman skeletons lack certain IK bones required for:
  - Foot IK
  - Interaction animations
  - Center of mass calculations

### Copy IK Bones from Mannequin

1. Open the **Mannequin skeletal mesh**.
2. Select all IK bones (including interaction + COM bones).
3. Copy them via the **Skeleton Editor toolbox**.
4. Open the **MetaHuman skeleton**.
5. Paste the IK bones.
6. Apply and save the skeleton and asset immediately  
   _(prevents editor crashes)_.  
   _(~00:08:30)_

---

## 4. Retargeting Animations

### Retarget Mannequin Animations

1. Open the **Mannequin Animation Blueprint**.
2. Use **Retarget Animations**.
3. Set:
   - **Source:** Mannequin
   - **Target:** MetaHuman skeletal mesh
4. Select the **modified retargeter** created earlier.
5. Export and save all retargeted assets.  
   _(~00:10:30)_

---

## 5. Setting Up the MetaHuman as a Playable Character

### Assign Skeletal Mesh & Animation Blueprint

- Open the **Third Person Character Blueprint**.
- Replace the mannequin skeletal mesh with the MetaHuman mesh.
- Swap the animation blueprint to the retargeted MetaHuman ABP.  
  _(~00:12:00)_

### Copy and Parent MetaHuman Components

1. From the MetaHuman blueprint, copy:
   - Face
   - Feet
   - Legs
   - Torso
   - Other body components
2. Paste them into the character blueprint.
3. Parent all components to the main body mesh.
4. Zero out **Location** and **Rotation** transforms.

### Set Leader Pose Component

- In the **Construction Script**, use:
