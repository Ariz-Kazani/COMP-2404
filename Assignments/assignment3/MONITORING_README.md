# Repository Monitoring Feature

## Overview
Added repository monitoring capability to the GetHub system to address the question: "is there a way I can monitor a public repo for changes?"

## New Features
The Client class now includes monitoring functionality that allows users to:
1. Download/clone a repository and automatically begin monitoring it
2. Check for changes between the local copy and the remote repository
3. Get detailed reports about what has changed

## New Menu Options
- **Option 9: Check for repo changes** - Quick check that returns whether changes are detected
- **Option 10: Show repo changes** - Detailed report showing exactly what changed

## How It Works
1. When you download a repository using option 6, the system automatically starts monitoring that repository
2. The system stores a snapshot of the repository state (file count, etc.) when first cloned
3. You can then use options 9 or 10 to check for changes against the current remote state
4. The system detects additions and removals of files by comparing file counts

## Example Usage
```
1. Select option 6 to download a repo (e.g., repo 0)
2. Select option 9 to quickly check for changes -> "No changes detected"
3. Use option 5 to remove a file from the remote repo
4. Select option 9 again -> "Changes detected in repository!"
5. Select option 10 for details -> Shows "1 file(s) removed"
```

## Example Output
When changes are detected, option 10 shows:
```
Repository Change Report
=========================
Monitoring: TechTrendsUnleashed by Bob
CHANGES DETECTED:
  Local file count: 5
  Remote file count: 4
  Status: 1 file(s) removed
```

When no changes are detected:
```
Repository Change Report
=========================
Monitoring: TechTrendsUnleashed by Bob
No changes detected - file count unchanged (5 files)
```

## Implementation Details
- Added `monitoredRepoIndex` field to Client class to track which repository is being monitored
- Added `checkForChanges()` method for quick boolean check
- Added `printChanges()` method for detailed change reports
- Modified `cloneRepo()` to automatically set up monitoring
- Extended Control class with new menu options and handlers
- Minimal changes to existing code - only added new functionality

## Limitations
- Currently only tracks file count changes (additions/removals)
- Only monitors one repository at a time per client
- Does not detect content modifications within files
- Simple comparison based on file counts

This implementation provides a solid foundation for repository monitoring that can be extended with more sophisticated change detection in the future.