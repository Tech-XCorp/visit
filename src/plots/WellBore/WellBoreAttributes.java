// ***************************************************************************
//
// Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400142
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit.plots;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;
import llnl.visit.ColorAttribute;
import llnl.visit.ColorAttributeList;
import java.lang.Integer;
import java.util.Vector;

// ****************************************************************************
// Class: WellBoreAttributes
//
// Purpose:
//    This class contains the plot attributes for the well bore plot.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class WellBoreAttributes extends AttributeSubject implements Plugin
{
    // Enum values
    public final static int WELLRENDERINGMODE_LINES = 0;
    public final static int WELLRENDERINGMODE_CYLINDERS = 1;

    public final static int DETAILLEVEL_LOW = 0;
    public final static int DETAILLEVEL_MEDIUM = 1;
    public final static int DETAILLEVEL_HIGH = 2;
    public final static int DETAILLEVEL_SUPER = 3;

    public final static int COLORINGMETHOD_COLORBYSINGLECOLOR = 0;
    public final static int COLORINGMETHOD_COLORBYMULTIPLECOLORS = 1;
    public final static int COLORINGMETHOD_COLORBYCOLORTABLE = 2;


    public WellBoreAttributes()
    {
        super(12);

        colorType = COLORINGMETHOD_COLORBYMULTIPLECOLORS;
        colorTableName = new String("Default");
        singleColor = new ColorAttribute(255, 0, 0);
        multiColor = new ColorAttributeList();
        drawWellsAs = WELLRENDERINGMODE_CYLINDERS;
        wellCylinderQuality = DETAILLEVEL_MEDIUM;
        wellRadius = 0.12f;
        wellLineWidth = 0;
        wellLineStyle = 0;
        legendFlag = true;
        nWellBores = 10;
        wellBores = new Vector();
    }

    public WellBoreAttributes(WellBoreAttributes obj)
    {
        super(12);

        int i;

        colorType = obj.colorType;
        colorTableName = new String(obj.colorTableName);
        singleColor = new ColorAttribute(obj.singleColor);
        multiColor = new ColorAttributeList(obj.multiColor);
        drawWellsAs = obj.drawWellsAs;
        wellCylinderQuality = obj.wellCylinderQuality;
        wellRadius = obj.wellRadius;
        wellLineWidth = obj.wellLineWidth;
        wellLineStyle = obj.wellLineStyle;
        legendFlag = obj.legendFlag;
        nWellBores = obj.nWellBores;
        wellBores = new Vector();
        for(i = 0; i < obj.wellBores.size(); ++i)
        {
            Integer iv = (Integer)obj.wellBores.elementAt(i);
            wellBores.addElement(new Integer(iv.intValue()));
        }

        SelectAll();
    }

    public boolean equals(WellBoreAttributes obj)
    {
        int i;

        // Compare the elements in the wellBores vector.
        boolean wellBores_equal = (obj.wellBores.size() == wellBores.size());
        for(i = 0; (i < wellBores.size()) && wellBores_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer wellBores1 = (Integer)wellBores.elementAt(i);
            Integer wellBores2 = (Integer)obj.wellBores.elementAt(i);
            wellBores_equal = wellBores1.equals(wellBores2);
        }
        // Create the return value
        return ((colorType == obj.colorType) &&
                (colorTableName.equals(obj.colorTableName)) &&
                (singleColor == obj.singleColor) &&
                (multiColor.equals(obj.multiColor)) &&
                (drawWellsAs == obj.drawWellsAs) &&
                (wellCylinderQuality == obj.wellCylinderQuality) &&
                (wellRadius == obj.wellRadius) &&
                (wellLineWidth == obj.wellLineWidth) &&
                (wellLineStyle == obj.wellLineStyle) &&
                (legendFlag == obj.legendFlag) &&
                (nWellBores == obj.nWellBores) &&
                wellBores_equal);
    }

    public String GetName() { return "WellBore"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetColorType(int colorType_)
    {
        colorType = colorType_;
        Select(0);
    }

    public void SetColorTableName(String colorTableName_)
    {
        colorTableName = colorTableName_;
        Select(1);
    }

    public void SetSingleColor(ColorAttribute singleColor_)
    {
        singleColor = singleColor_;
        Select(2);
    }

    public void SetMultiColor(ColorAttributeList multiColor_)
    {
        multiColor = multiColor_;
        Select(3);
    }

    public void SetDrawWellsAs(int drawWellsAs_)
    {
        drawWellsAs = drawWellsAs_;
        Select(4);
    }

    public void SetWellCylinderQuality(int wellCylinderQuality_)
    {
        wellCylinderQuality = wellCylinderQuality_;
        Select(5);
    }

    public void SetWellRadius(float wellRadius_)
    {
        wellRadius = wellRadius_;
        Select(6);
    }

    public void SetWellLineWidth(int wellLineWidth_)
    {
        wellLineWidth = wellLineWidth_;
        Select(7);
    }

    public void SetWellLineStyle(int wellLineStyle_)
    {
        wellLineStyle = wellLineStyle_;
        Select(8);
    }

    public void SetLegendFlag(boolean legendFlag_)
    {
        legendFlag = legendFlag_;
        Select(9);
    }

    public void SetNWellBores(int nWellBores_)
    {
        nWellBores = nWellBores_;
        Select(10);
    }

    public void SetWellBores(Vector wellBores_)
    {
        wellBores = wellBores_;
        Select(11);
    }

    // Property getting methods
    public int                GetColorType() { return colorType; }
    public String             GetColorTableName() { return colorTableName; }
    public ColorAttribute     GetSingleColor() { return singleColor; }
    public ColorAttributeList GetMultiColor() { return multiColor; }
    public int                GetDrawWellsAs() { return drawWellsAs; }
    public int                GetWellCylinderQuality() { return wellCylinderQuality; }
    public float              GetWellRadius() { return wellRadius; }
    public int                GetWellLineWidth() { return wellLineWidth; }
    public int                GetWellLineStyle() { return wellLineStyle; }
    public boolean            GetLegendFlag() { return legendFlag; }
    public int                GetNWellBores() { return nWellBores; }
    public Vector             GetWellBores() { return wellBores; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(colorType);
        if(WriteSelect(1, buf))
            buf.WriteString(colorTableName);
        if(WriteSelect(2, buf))
            singleColor.Write(buf);
        if(WriteSelect(3, buf))
            multiColor.Write(buf);
        if(WriteSelect(4, buf))
            buf.WriteInt(drawWellsAs);
        if(WriteSelect(5, buf))
            buf.WriteInt(wellCylinderQuality);
        if(WriteSelect(6, buf))
            buf.WriteFloat(wellRadius);
        if(WriteSelect(7, buf))
            buf.WriteInt(wellLineWidth);
        if(WriteSelect(8, buf))
            buf.WriteInt(wellLineStyle);
        if(WriteSelect(9, buf))
            buf.WriteBool(legendFlag);
        if(WriteSelect(10, buf))
            buf.WriteInt(nWellBores);
        if(WriteSelect(11, buf))
            buf.WriteIntVector(wellBores);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetColorType(buf.ReadInt());
                break;
            case 1:
                SetColorTableName(buf.ReadString());
                break;
            case 2:
                singleColor.Read(buf);
                Select(2);
                break;
            case 3:
                multiColor.Read(buf);
                Select(3);
                break;
            case 4:
                SetDrawWellsAs(buf.ReadInt());
                break;
            case 5:
                SetWellCylinderQuality(buf.ReadInt());
                break;
            case 6:
                SetWellRadius(buf.ReadFloat());
                break;
            case 7:
                SetWellLineWidth(buf.ReadInt());
                break;
            case 8:
                SetWellLineStyle(buf.ReadInt());
                break;
            case 9:
                SetLegendFlag(buf.ReadBool());
                break;
            case 10:
                SetNWellBores(buf.ReadInt());
                break;
            case 11:
                SetWellBores(buf.ReadIntVector());
                break;
            }
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "colorType = ";
        if(colorType == COLORINGMETHOD_COLORBYSINGLECOLOR)
            str = str + "COLORINGMETHOD_COLORBYSINGLECOLOR";
        if(colorType == COLORINGMETHOD_COLORBYMULTIPLECOLORS)
            str = str + "COLORINGMETHOD_COLORBYMULTIPLECOLORS";
        if(colorType == COLORINGMETHOD_COLORBYCOLORTABLE)
            str = str + "COLORINGMETHOD_COLORBYCOLORTABLE";
        str = str + "\n";
        str = str + stringToString("colorTableName", colorTableName, indent) + "\n";
        str = str + indent + "singleColor = {" + singleColor.Red() + ", " + singleColor.Green() + ", " + singleColor.Blue() + ", " + singleColor.Alpha() + "}\n";
        str = str + indent + "multiColor = {\n" + multiColor.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "drawWellsAs = ";
        if(drawWellsAs == WELLRENDERINGMODE_LINES)
            str = str + "WELLRENDERINGMODE_LINES";
        if(drawWellsAs == WELLRENDERINGMODE_CYLINDERS)
            str = str + "WELLRENDERINGMODE_CYLINDERS";
        str = str + "\n";
        str = str + indent + "wellCylinderQuality = ";
        if(wellCylinderQuality == DETAILLEVEL_LOW)
            str = str + "DETAILLEVEL_LOW";
        if(wellCylinderQuality == DETAILLEVEL_MEDIUM)
            str = str + "DETAILLEVEL_MEDIUM";
        if(wellCylinderQuality == DETAILLEVEL_HIGH)
            str = str + "DETAILLEVEL_HIGH";
        if(wellCylinderQuality == DETAILLEVEL_SUPER)
            str = str + "DETAILLEVEL_SUPER";
        str = str + "\n";
        str = str + floatToString("wellRadius", wellRadius, indent) + "\n";
        str = str + intToString("wellLineWidth", wellLineWidth, indent) + "\n";
        str = str + intToString("wellLineStyle", wellLineStyle, indent) + "\n";
        str = str + boolToString("legendFlag", legendFlag, indent) + "\n";
        str = str + intToString("nWellBores", nWellBores, indent) + "\n";
        str = str + intVectorToString("wellBores", wellBores, indent) + "\n";
        return str;
    }


    // Attributes
    private int                colorType;
    private String             colorTableName;
    private ColorAttribute     singleColor;
    private ColorAttributeList multiColor;
    private int                drawWellsAs;
    private int                wellCylinderQuality;
    private float              wellRadius;
    private int                wellLineWidth;
    private int                wellLineStyle;
    private boolean            legendFlag;
    private int                nWellBores;
    private Vector             wellBores; // vector of Integer objects
}

